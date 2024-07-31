from setuptools import find_packages
from setuptools import setup

setup(
    name='lawd_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('lawd_msgs', 'lawd_msgs.*')),
)
