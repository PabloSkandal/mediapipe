load("//mediapipe/examples/desktop/library_win:windows_dll_library.bzl", "windows_dll_library")

filegroup(
    name = "srcs",
    srcs = glob(["**"]),
    visibility = ["//examples:__pkg__"],
)

package(default_visibility = ["//mediapipe/examples:__subpackages__"])

# Define the shared library
windows_dll_library(
    name = "libmediapipe",
    srcs = ["mediapipe.cpp", "mediapipe_impl.cpp"],
    hdrs = ["mp_bbox.h", "mediapipe.h", "mediapipe_impl.h"],
    # Define COMPILING_DLL to export symbols during compiling the DLL.
    copts = ["-DCOMPILING_DLL"],
    deps = [
        # Deps for mediapipe_impl.cpp
        "//mediapipe/framework/port:parse_text_proto",
        "@com_google_absl//absl/flags:parse",
        "//mediapipe/calculators/core:packet_resampler_calculator",
        "//mediapipe/graphs/tracking/subgraphs:object_detection_cpu",
        "//mediapipe/graphs/tracking/subgraphs:object_tracking_cpu",

        "//mediapipe/framework/formats:detection_cc_proto",
        
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
)
