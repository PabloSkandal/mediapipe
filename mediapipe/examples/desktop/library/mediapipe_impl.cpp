 #include "mediapipe_impl.h"
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/file_helpers.h"
#include "mediapipe/framework/port/parse_text_proto.h"
#include "mediapipe/framework/port/status.h"
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/framework/formats/detection.pb.h"

namespace mediapipe {
constexpr char kInputStream[] = "input_video";
constexpr char kOutputStream[] = "output_detections";

MediapipeImpl::~MediapipeImpl() 
{
    LOG(INFO) << "Shutting down.";
    absl::Status status = m_graph.CloseInputStream(kInputStream);
    if (status.ok()){
    	absl::Status status1 = m_graph.WaitUntilDone();
        if (!status1.ok()) {
            LOG(INFO) << "Error in WaitUntilDone(): " << status1.ToString();
        }
    } else {
        LOG(INFO) << "Error in CloseInputStream(): " << status.ToString();
    }
}

absl::Status MediapipeImpl::Init(const std::string& graph) 
{
    LOG(INFO) << "Parsing graph config " << graph;
    mediapipe::CalculatorGraphConfig config = mediapipe::ParseTextProtoOrDie<mediapipe::CalculatorGraphConfig>(graph);

    LOG(INFO) << "Initialize the calculator graph.";
    MP_RETURN_IF_ERROR(m_graph.Initialize(config));

    LOG(INFO) << "Start running the calculator graph.";
    ASSIGN_OR_RETURN(m_poller, m_graph.AddOutputStreamPoller(kOutputStream));
    MP_RETURN_IF_ERROR(m_graph.StartRun({}));

    return absl::OkStatus();
}

std::vector<Detection> MediapipeImpl::Process(uint8_t* data, int width, int height) 
{
    if (data == nullptr){
        LOG(INFO) << __FUNCTION__ << " input data is nullptr!";
        return {};
    }

    int width_step = width * ImageFrame::ByteDepthForFormat(ImageFormat::SRGB) * ImageFrame::NumberOfChannelsForFormat(ImageFormat::SRGB);

    auto input_frame_for_input = absl::make_unique<ImageFrame>(ImageFormat::SRGB, width, height, width_step, 
                                                                (uint8*)data, ImageFrame::PixelDataDeleter::kNone);

    m_frame_timestamp++;

    if (!m_graph.AddPacketToInputStream(kInputStream, mediapipe::Adopt(input_frame_for_input.release()).At(mediapipe::Timestamp(m_frame_timestamp))).ok()) {
        LOG(INFO) << "Failed to add packet to input stream. Call m_graph.WaitUntilDone() to see error (or destroy Mediapipe object)";
        return {};
    }

    mediapipe::Packet packet;
    if (!m_poller->Next(&packet)){
        LOG(INFO) << "Poller didnt give me a packet, sorry. Call m_graph.WaitUntilDone() to see error (or destroy Mediapipe object). Error probably is that models are not available under mediapipe/models or mediapipe/modules";
        return {};
    }

    return packet.Get<std::vector<Detection>>(); 
}

}
