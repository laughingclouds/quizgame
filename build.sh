PROJECT_ROOT=$(pwd)
BUILD_PATH=$PROJECT_ROOT/build/

mkdir -p build

# BACKEND_BUILD_PATH=$PROJECT_ROOT/build/

cd $PROJECT_ROOT/frontend/
yarn build


cd $PROJECT_ROOT/backend/

echo "Copy all static files into $BUILD_PATH"
cp static/media/* $BUILD_PATH/static/media/

echo "Building backend into $BUILD_PATH"
go build -o $BUILD_PATH

echo "Done"
