# CarDetection

A custom haar cascade created to best detect the front of cars. [For more information](https://themadphysicist.com/vehicle-detection-w-opencv-haar-cascades/)

## Ubuntu Build instructions
```
sudo apt install git cmake libopencv-dev
git clone https://github.com/anhydrous99/CarDetection
cd CarDetection
mkdir build && cd build
cmake ..
make
cp ../cascade_data/cascade2.xml .
./CarDetection
```
