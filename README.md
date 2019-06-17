# CMake Project Templates

CMake is a great tool, but using it can get complicated when a code project uses or even combines certain frameworks. This repository contains a collection of barebone CMake project templates for various specific setups:


*  **CMake (nothing else)**
   Simply a very generic CMake project structure for C++ projects.

*  **CMake + CUDA**
   Using CMake to manage a C++ project that contains CUDA code.

*  **CMake + Multithreading**
   If you want to use `std::thread` or `pthread`, CMake needs to be configured accordingly.

*  **CMake + ROS**
   This project can be compiled using `rosmake`. Tested with ROS Indigo.

*  **CMake + Boost + CUDA + ROS**
   Sometimes, you need it all. Each of Boost, CUDA and ROS need special attention when it comes to CMake. This setup combines all of them, so now you can `rosmake` your GPU projects. Tested with ROS Indigo


# CMake Project Template for *ROS Kinetic*

* **generic-ros-catkin-cplusplus-cmake-example**<br/>
  A barebones C++ ROS package template

* **generic-ros-catkin-cplusplus-actions-cmake-example**<br/>
  Using custom ROS actions

* **generic-ros-catkin-cplusplus-launchfiles-cmake-example**<br/>
  Using custom launchfiles for your project

* **generic-ros-catkin-cplusplus-messages-cmake-example**<br/>
  Using custom ROS messages

* **generic-ros-catkin-cplusplus-services-cmake-example**<br/>
  Using custom ROS services

* **generic-ros-catkin-python-cmake-example**<br/>
  A barebones Python ROS package template

* **generic-ros-catkin-python-launchfiles-cmake-example**<br/>
  Using custom launchfiles




## Usage

*  Clone this repository:
   ```bash
   git clone https://github.com/nikolausmayer/cmake-templates
   ```

*  In whatever subfolder, use the standard CMake procedure:
   ```bash
   cd cmake-templates/generic-cmake-example
   mkdir build
   cd build
   cmake ..
   make -j && make install
   ```
   For the ROS Indigo templates, `rosmake` can be used instead.
   For the ROS Kinetic templates, `catkin_make` can be used instead.


