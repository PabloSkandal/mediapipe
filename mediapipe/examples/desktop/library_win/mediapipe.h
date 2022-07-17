#pragma once

#ifdef COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#include "mp_bbox.h"
#include <vector>

namespace mediapipe {

class DLLEXPORT Mediapipe {
public:
    // Create and initialize using provided graph
    // Returns nullptr if initialization failed
    static Mediapipe* Create(const std::string& graph);
    static void Destroy(Mediapipe* instance);

    virtual ~Mediapipe(){}

    // Processes one frame and blocks until finished
    // Input data is expected to be ImageFormat::SRGB (24bits)
    // Returns nullptr if failed to run graph
    // Returns pointer to image whose size is the same as input image
    // and whose format is ImageFormat::SRGB
    // ImageFormat::SRGB is QImage::Format_RGB888 in Qt
    // Function does not take ownership of input data
    virtual std::vector<mp_bbox_t> Process(uint8_t* data, int width, int height) = 0;
};

}
