#include "mediapipe.h"
#include "mediapipe_impl.h"

namespace mediapipe {

Mediapipe* Mediapipe::Create(const std::string& graph)
{
    MediapipeImpl *mediapipe = new MediapipeImpl();
    absl::Status status = mediapipe->Init(graph);
    if (status.ok()){
        return mediapipe;
    }
    else{
        LOG(INFO) << "Error initializing graph " << status.ToString();
        delete mediapipe;
        return nullptr;
    }
}

void Mediapipe::Destroy(Mediapipe* instance)
{
    if (instance) {
        delete instance;
    }
}

}
