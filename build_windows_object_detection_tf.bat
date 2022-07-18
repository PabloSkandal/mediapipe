set BAZEL_VS=C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools
set BAZEL_VC=C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC
set BAZEL_VC_FULL_VERSION=14.29.30133
set BAZEL_WINSDK_FULL_VERSION=10.0.19041.0

bazel build -c opt --define MEDIAPIPE_DISABLE_GPU=1 --define no_aws_support=true --linkopt=-s --action_env PYTHON_BIN_PATH="C://Users//GTI//AppData//Local//Programs//Python//Python310//python.exe" mediapipe/examples/desktop/object_detection:object_detection_tensorflow >> log_opt.txt

set GLOG_logtostderr=1
bazel-bin/mediapipe/examples/desktop/object_detection/object_detection_tflite.exe --calculator_graph_config_file=mediapipe/graphs/object_detection/object_detection_desktop_tensorflow_graph.pbtxt --input_side_packets=input_video_path=mediapipe/examples/desktop/object_detection/test_video.mp4,output_video_path=<mediapipe/examples/desktop/object_detection/test_video_out.mp4>