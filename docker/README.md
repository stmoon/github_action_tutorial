# ROS 2 Humble + PX4 (Ubuntu 22.04 Jammy) Docker 개발 환경

이 Docker 환경은 **Ubuntu 22.04 (Jammy)** 기반으로  
**ROS 2 Humble**과 **PX4 개발 환경**을 쉽게 구축할 수 있도록 구성되었습니다.

컨테이너 내부에서 ROS 2 패키지 빌드 및 PX4 펌웨어를 사용할 수 있으며,  
GUI 및 GPU 사용도 지원할 수 있도록 옵션을 제공합니다.


## Docker 이미지 빌드 방법

### Docker CLI 사용
```bash
cd docker
docker build -t fireswarm__px4_ros2 .
```


## Docker 컨테이너 실행 방법

**프로젝트 최상단 디렉토리에서 아래 명령어를 실행하세요**
 ```bash
 cd /path/to/FireSearchDroneSystem  # 프로젝트 최상단으로 이동
 ```
- PX4-Autopilot 경로는 FireSearchDroneSystem과 같은 상위 디렉토리에 있어야 합니다.
- PX4-Autopilot을 사용하지 않는 경우, 아래 명령어에서 PX4-Autopilot 관련 볼륨 마운트 줄 (`-v $(realpath ../PX4-Autopilot):/home/user/PX4-Autopilot:rw`)은 제거해도 됩니다:


```bash
docker run -it --rm \
    -e DISPLAY=${DISPLAY} \
    -e LOCAL_USER_ID="$(id -u)" \
    -v $(realpath ../PX4-Autopilot):/home/user/PX4-Autopilot:rw \
    -v $(pwd)/src:/home/user/ros2_ws/src:rw \
    -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
    --name=fireswarm_dev_container \
    fireswarm__px4_ros2 /bin/bash
```

### GPU 사용 시 실행 방법
``` bash
docker run -it --rm \
    --gpus all \
    -e NVIDIA_DRIVER_CAPABILITIES=all \
    -e DISPLAY=${DISPLAY} \
    -e LOCAL_USER_ID="$(id -u)" \
    -v $(realpath ../PX4-Autopilot):/home/user/PX4-Autopilot:rw \
    -v $(pwd)/src:/home/user/ros2_ws/src:rw \
    -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
    -w /home/user \
    --name=fireswarm_dev_container \
    fireswarm__px4_ros2 /bin/bash
```
#### ⚠️ GPU 사용 주의사항
> - 호스트 머신에 NVIDIA Container Toolkit이 설치되어 있어야 합니다.
> - 참고 : [설치](https://docs.nvidia.com/datacenter/cloud-native/container-toolkit/latest/install-guide.html), [GPU 관련 설정](https://docs.nvidia.com/datacenter/cloud-native/container-toolkit/latest/docker-specialized.html)