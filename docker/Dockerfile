# PX4 ROS2 Humble development environment (Ubuntu 22.04)
# Based on px4-jammy container + ROS2 Humble installation

FROM px4io/px4-dev-base-jammy:2024-05-18

LABEL maintainer="SongSiWoon <siwoons7319@gmail.com>"

ENV ROS_DISTRO=humble

# Install basic tools
RUN apt-get update && apt-get install --quiet -y \
    sudo \
    vim \
    && apt-get -y autoremove \
    && apt-get clean autoclean \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Add ROS2 GPG key and repository
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg \
    && echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/ros2.list

# Install ROS2 Humble tools
RUN apt-get update && apt-get install --quiet -y \
    python3-colcon-common-extensions \
    python3-colcon-mixin \
    python3-rosdep \
    python3-vcstool \
    ros-$ROS_DISTRO-desktop \
    ros-$ROS_DISTRO-launch-testing-ament-cmake \
    ros-$ROS_DISTRO-ros2bag \
    ros-$ROS_DISTRO-rosidl-generator-dds-idl \
    && rosdep init && rosdep update \
    && apt-get -y autoremove \
    && apt-get clean autoclean \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Install Python packages for testing and linting
RUN pip3 install -U \
    argcomplete \
    flake8 \
    flake8-blind-except \
    flake8-builtins \
    flake8-class-newline \
    flake8-comprehensions \
    flake8-deprecated \
    flake8-docstrings \
    flake8-import-order \
    flake8-quotes \
    pytest-repeat \
    pytest-rerunfailures

# Passwordless sudo for 'user'
RUN echo 'user ALL=(ALL) NOPASSWD:ALL' > /etc/sudoers.d/nopasswd \
    && chmod 440 /etc/sudoers.d/nopasswd

# Setup colcon mixin and metadata
RUN colcon mixin add default https://raw.githubusercontent.com/colcon/colcon-mixin-repository/master/index.yaml \
    && colcon mixin update \
    && colcon metadata add default https://raw.githubusercontent.com/colcon/colcon-metadata-repository/master/index.yaml \
    && colcon metadata update

# Entrypoint
COPY scripts/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

CMD ["/bin/bash"]
