#pragma once

#include <string>

struct mp_bbox_t {
    float x=0, y=0, w=0, h=0; // (x,y) - top-left corner, (w, h) - width & height of bounded box
    float prob = 0.0f;               // confidence - probability that the object was found correctly
    std::string obj_name;         // class of object - from range [0, classes-1]
    int track_id = 0;       // tracking id for video (0 - untracked, 1 - inf - tracked object)
};
