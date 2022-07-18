#pragma once

#include "mediapipe.h"
#include "absl/status/status.h"
#include "mediapipe/framework/calculator_framework.h"

namespace mediapipe {

class DLLEXPORT MediapipeImpl : public Mediapipe {
public:
    MediapipeImpl(){}
    virtual ~MediapipeImpl() override;

    absl::Status Init(const std::string& graph);

    std::vector<mp_bbox_t> Process(uint8_t* data, int width, int height) override;

private:
    mediapipe::CalculatorGraph m_graph;
    absl::StatusOr<OutputStreamPoller> m_poller;
    size_t m_frame_timestamp = 0;
};

}
