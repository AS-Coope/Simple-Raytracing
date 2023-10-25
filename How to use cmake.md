# Using CMAKE

## Important Note
These instructions pertain to Linux (specifically, Ubuntu).

## Instructions
1. Create the directory where build file will go.
Eg: From root (directory, that is, the project's root directory), run:   
`mkdir -p out/build`

2. Create the CMakeLists.txt file in the root directory.  
NOTE: CMakeLists.txt should be written exactly like that, with capital C, M and L. In other words, it is case sensitive.  
`touch CMakeLists.txt`

3. Run   
`cmake -S <path-to-source-dir> -B <path-to-build-dir>`  
NOTE: In this case, the source directory is the root directory of the project.

4. In the root directory, open the CMakeLists.txt file.
Add the following:
  ```
  cmake_minimum_required(VERSION <usually-put-current-cmake-version>)

  project(<project-name-goes-here>)

  add_executable(${PROJECT_NAME} <name-of-cpp-file>)
  ```

For now the .cpp file would be in the root directory 
(Currently, mine resides there, but I assume I'll have a folder for .cpp
files when there are many more being used).

5. Navigate to the build folder and run  
`make`

### Further notes pertain specifically to raytracing in one weekend and making .ppm files

Redirect the output of the file generated from running the make command
(this will be the project name you specified in the project function from step 4)
to a file with .ppm as its file extension, using the redirection operator '>'.
Eg:   
`./<project-name> > <image_file_name>.ppm`  
NOTE: This assumes your current working directory is the build folder, otherwise, replace `.` to the path to the build directory.

