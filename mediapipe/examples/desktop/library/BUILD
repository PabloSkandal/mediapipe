licenses(["notice"])

package(default_visibility = ["//mediapipe/examples:__subpackages__"])

cc_binary(
    name = "libmediapipe.so",
    deps = [
        ":bg_remover"
    ],
    linkopts = ["-Wl,-soname,libmediapipe.so"],
    linkshared = 1 ## Very important
)

cc_library(
    name = "bg_remover",
    srcs = ["mediapipe.cpp", "mediapipe_impl.cpp"],
    hdrs = ["mediapipe.h", "mediapipe_impl.h"],
    visibility = ["//visibility:public"],
    deps = [
        # Deps for mediapipe_impl.cpp
        "//mediapipe/framework/port:parse_text_proto",
        "@com_google_absl//absl/flags:parse",

        # Object detection
        "//mediapipe/calculators/core:concatenate_vector_calculator",
        "//mediapipe/calculators/core:flow_limiter_calculator",
        "//mediapipe/calculators/core:previous_loopback_calculator",
        "//mediapipe/calculators/core:split_vector_calculator",
        "//mediapipe/calculators/tflite:ssd_anchors_calculator",
        "//mediapipe/calculators/tflite:tflite_converter_calculator",
        "//mediapipe/calculators/tflite:tflite_inference_calculator",
        "//mediapipe/calculators/tflite:tflite_tensors_to_detections_calculator",
        "//mediapipe/calculators/util:detection_label_id_to_text_calculator",
        "//mediapipe/calculators/util:non_max_suppression_calculator",


	],
    alwayslink = 1,
)
