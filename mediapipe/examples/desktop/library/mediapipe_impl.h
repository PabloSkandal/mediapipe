#pragma once

#include "mediapipe.h"
#include "absl/status/status.h"
#include "mediapipe/framework/calculator_framework.h"

namespace mediapipe {

class MediapipeImpl : public Mediapipe {
public:
    MediapipeImpl(){}
    ~MediapipeImpl();

    absl::Status Init(const std::string& graph);

    std::vector<Detection> Process(uint8_t* data, int width, int height) override;

private:
    mediapipe::CalculatorGraph m_graph;
    absl::StatusOr<OutputStreamPoller> m_poller;
    size_t m_frame_timestamp = 0;
};

}
