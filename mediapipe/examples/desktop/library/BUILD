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
        "//mediapipe/calculators/core:packet_resampler_calculator",
        "//mediapipe/graphs/tracking/subgraphs:object_detection_cpu",
        "//mediapipe/graphs/tracking/subgraphs:object_tracking_cpu",
        
        # ObjectDetectionSubgraphCpu
        "//mediapipe/calculators/image:image_transformation_calculator",
        "//mediapipe/calculators/tflite:ssd_anchors_calculator",
        "//mediapipe/calculators/tflite:tflite_converter_calculator",
        "//mediapipe/calculators/tflite:tflite_inference_calculator",
        "//mediapipe/calculators/tflite:tflite_tensors_to_detections_calculator",
        "//mediapipe/calculators/util:detection_label_id_to_text_calculator",
        "//mediapipe/calculators/util:non_max_suppression_calculator",
        
        # ObjectTrackingSubgraphCpu
        "//mediapipe/calculators/util:detection_unique_id_calculator",
        "//mediapipe/calculators/util:detections_to_timed_box_list_calculator",
        "//mediapipe/calculators/video:tracked_detection_manager_calculator",
        "//mediapipe/framework/stream_handler:sync_set_input_stream_handler",
        "//mediapipe/graphs/tracking/subgraphs:box_tracking_cpu",
        
        # BoxTrackingSubgraphCpu
        "//mediapipe/calculators/video:box_tracker_calculator",
        "//mediapipe/calculators/video:flow_packager_calculator",
        "//mediapipe/calculators/video:motion_analysis_calculator",
        "//mediapipe/framework/stream_handler:immediate_input_stream_handler",
        
	],
    alwayslink = 1,
)
