set BAZEL_VS=C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools
set BAZEL_VC=C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC
set BAZEL_VC_FULL_VERSION=14.29.30133
set BAZEL_WINSDK_FULL_VERSION=10.0.19041.0

bazel build -c dbg --define MEDIAPIPE_DISABLE_GPU=1 --action_env PYTHON_BIN_PATH="C://Users//GTI//AppData//Local//Programs//Python//Python310//python.exe" mediapipe/examples/desktop/object_detection:object_detection_cpu

set GLOG_logtostderr=1
bazel-bin\mediapipe\examples\desktop\object_detection\object_detection_cpu.exe --calculator_graph_config_file=mediapipe/graphs/object_detection/object_detection_desktop_live.pbtxt