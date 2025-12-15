emcc ./src/*.c -o ./out/main.js -s MAX_WEBGL_VERSION=2  -s EXPORTED_RUNTIME_METHODS='['HEAPU8', 'HEAPU16', 'HEAPU32', 'HEAPF32']' -s USE_GLFW=1 --preload-file ./res/@/ \
-s MAX_WEBGL_VERSION=2 \
-s MIN_WEBGL_VERSION=2 \
-s FULL_ES3