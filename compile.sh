cd $(dirname $0)

rm -f rt
rm -rf build

mkdir -p build
cd build
cmake ..
make -j4

cp ./rt ../rt