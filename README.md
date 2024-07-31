# LAWD_WS: Legged Autonomous Drone with 2DOF Legs

Welcome to the LAWD_WS project! This repository contains the ROS 2 (Humble) workspace for a legged autonomous drone equipped with four legs, each with two degrees of freedom (2DOF). The drone is designed for precision landing and has been modeled in Fusion 360 and integrated with ROS 2 controllers.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Development](#development)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Overview

The LAWD_WS project aims to create a versatile drone capable of precision landing using its unique leg design. Each leg has 2DOF, allowing for fine-tuned control and stability during landing. The drone is designed and simulated in Fusion 360, with ROS 2 (Humble) providing the framework for control and automation.

## Features

- **2DOF Legs:** Each leg has two degrees of freedom, enabling complex movements for precision landing.
- **Fusion 360 Design:** The entire drone is modeled in Fusion 360, allowing for accurate simulations and real-world testing.
- **ROS 2 Integration:** The drone's control systems are integrated with ROS 2, providing a robust framework for communication and control.
- **Forward Command Controller:** The legs operate using a forward command controller, which interprets high-level commands into precise movements.

## Installation

### Prerequisites

- **ROS 2 Humble:** Ensure that ROS 2 Humble is installed on your system. You can follow the [official installation guide](https://docs.ros.org/en/humble/Installation.html) for detailed instructions.

- **Additional Dependencies:** Install additional dependencies required for the project.

  ```bash
  sudo apt update
  sudo apt install <list-of-packages>

### Setup

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Vedhamshbode/LAWD_WS.git
   cd LAWD_WS
2.**Build the Workspace:**
   ```bash
     colcon build

