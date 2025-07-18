docker run -it --rm \
    -e DISPLAY=${DISPLAY} \
    -e LOCAL_USER_ID="$(id -u)" \
    -v /home/stmoon/Projects/PX4Swarm:/home/user/PX4-Autopilot:rw \
    -v $(pwd)/src:/home/user/ros2_ws/src:rw \
    -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
    --name=fireswarm_dev_container \
    fireswarm__px4_ros2 /bin/bash
