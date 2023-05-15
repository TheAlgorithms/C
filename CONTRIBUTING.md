# CONTRIBUTION GUIDELINES

## Before contributing

Welcome to [TheAlgorithms/C](https://github.com/TheAlgorithms/C)! Before submitting pull requests, please make sure that you have **read the whole guidelines**. If you have any doubts about this contribution guide, please open [an issue](https://github.com/TheAlgorithms/C/issues/new/choose) or ask on our [Discord server](https://the-algorithms.com/discord/), and clearly state your concerns.

## Contributing

### Maintainer/reviewer

**Please check the [reviewer code](https://github.com/TheAlgorithms/C/blob/master/REVIEWER_CODE.md) file for maintainers and reviewers.**

### Contributor

Being a contributor at The Algorithms, we request you to follow the points mentioned below:

- You did your own work.
  - No plagiarism is allowed. Any plagiarized work will not be merged.
- Your work will be distributed under the [GNU General Public License v3.0](https://github.com/TheAlgorithms/C/blob/master/LICENSE) once your pull request has been merged.
- Please follow the repository guidelines and standards mentioned below.

**New implementation** New implementations are welcome!

You can add new algorithms or data structures that are **not present in the repository** or that can **improve** the old implementations (**documentation**, **improving test cases**, removing bugs, or in any other reasonable sense)

**Issues** Please avoid opening issues asking to be "assigned” to a particular algorithm. This merely creates unnecessary noise for maintainers. Instead, please submit your implementation in a pull request, and it will be evaluated by project maintainers.

### LeetCode solutions

For LeetCode solutions, please check its [**guide**](https://github.com/TheAlgorithms/C/blob/master/leetcode/README.md) to make a proper solution file.

### Making Changes

#### Code

- Please use the directory structure of the repository.
- Make sure the file extensions should be `*.h` `*.c`
- Organize your code using the **`struct`** keyword
- If an implementation of the algorithm already exists, please refer to the [file-name section below](#file-name-guidelines).
- You can suggest reasonable changes to existing algorithms.
- Strictly use snake_case (underscore_separated) in filenames.
- If you have added or modified code, please make sure the code compiles before submitting.
- Our automated testing runs [**CMake**](https://cmake.org/) on all the pull requests, so please be sure that your code passes before submitting.
- Please conform to [Doxygen](https://www.doxygen.nl/manual/docblocks.html) standards and document the code as much as possible. This not only facilitates the readers but also generates the correct info on the website.
- **Be consistent in the use of these guidelines.**

#### Documentation

- Make sure you put useful comments in your code. Do not comment on obvious things.
- Please avoid creating new directories if at all possible. Try to fit your work into the existing directory structure. If you want to create a new directory, then please check if a similar category has been recently suggested or created by other pull requests.
- If you have modified/added documentation, please ensure that your language is concise and must not contain grammatical errors.
- Do not update [`README.md`](https://github.com/TheAlgorithms/C/blob/master/README.md) along with other changes. First, create an issue and then link to that issue in your pull request to suggest specific changes required to [`README.md`](https://github.com/TheAlgorithms/C/blob/master/README.md).
- The repository follows [Doxygen](https://www.doxygen.nl/manual/docblocks.html) standards and auto-generates the [repository website](https://thealgorithms.github.io/C). Please ensure the code is documented in this structure. A sample implementation is given below.

#### Test

- Make sure to add examples and test cases in your `main()` function.
- If you find an algorithm or document without tests, please feel free to create a pull request or issue describing suggested changes.
- Please try to add one or more `test()` functions that will invoke the algorithm implementation on random test data with the expected output. Use the `assert()` function to confirm that the tests will pass. Requires including the `assert.h` library.
- Test cases should fully verify that your program works as expected. Rather than asking the user for input, it's best to make sure the given output is the correct output.

##### Self-test examples

1. [ROT13 Cipher](https://github.com/TheAlgorithms/C/blob/master/cipher/rot13.c) (complex).

```c
    // NOTE: the `rot13` function is defined in another part of the code.

    char test_01[] = "The more I C, the less I see.";
    rot13(test_01);
    assert(strcmp(test_01, "Gur zber V P, gur yrff V frr.") == 0);

    char test_02[] = "Which witch switched the Swiss wristwatches?";
    rot13(test_02);
    assert(strcmp(test_02, "Juvpu jvgpu fjvgpurq gur Fjvff jevfgjngpurf?") == 0);

    char test_03[] = "Juvpu jvgpu fjvgpurq gur Fjvff jevfgjngpurf?";
    rot13(test_03);
    assert(strcmp(test_03, "Which witch switched the Swiss wristwatches?") == 0);
```

2. [Sudoku Solver](https://github.com/TheAlgorithms/C/blob/master/misc/sudoku_solver.c) (medium).

```c
    uint8_t test_array[] = {3, 0, 6, 5, 0, 8, 4, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0,
                            0, 0, 8, 7, 0, 0, 0, 0, 3, 1, 0, 0, 3, 0, 1, 0, 0,
                            8, 0, 9, 0, 0, 8, 6, 3, 0, 0, 5, 0, 5, 0, 0, 9, 0,
                            6, 0, 0, 1, 3, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0,
                            0, 0, 7, 4, 0, 0, 5, 2, 0, 6, 3, 0, 0};
    struct sudoku a = {.N = 9, .N2 = 3, .a = test_array};
    assert(solve(&a));  // ensure that solution is obtained
                        // NOTE: `solve` is defined in another part of the code.

    uint8_t expected[] = {3, 1, 6, 5, 7, 8, 4, 9, 2, 5, 2, 9, 1, 3, 4, 7, 6,
                          8, 4, 8, 7, 6, 2, 9, 5, 3, 1, 2, 6, 3, 4, 1, 5, 9,
                          8, 7, 9, 7, 4, 8, 6, 3, 1, 2, 5, 8, 5, 1, 7, 9, 2,
                          6, 4, 3, 1, 3, 8, 9, 4, 7, 2, 5, 6, 6, 9, 2, 3, 5,
                          1, 8, 7, 4, 7, 4, 5, 2, 8, 6, 3, 1, 9};
    for (int i = 0; i < a.N; i++)
        for (int j = 0; j < a.N; j++)
            assert(a.a[i * a.N + j] == expected[i * a.N + j]);
```

3. Small C program that showcases and explains the use of tests.

```c
#include <stdio.h>      /// for IO operations
#include <assert.h>     /// for assert
#include <stdbool.h>    /// for bool

/**
 * @brief Verifies if the given array
 * contains the given number on it.
 * @param arr the array to be used for checking
 * @param number the number to check if it's inside the array
 * @return false if the number was NOT found in the array
 * @return true if the number WAS found in the array
 */
bool is_number_on_array(const int *arr, const int number) {
    for (int i = 0; i < sizeof(arr); i++) {
        if (arr[i] == number) {
            return true;
        }
        else {
            // Number not in the current index, keep searching.
        }
    }

    return false;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void tests() {
    int arr[] = { 9, 14, 21, 98, 67 };

    assert(is_number_on_array(arr, 9) == true);
    assert(is_number_on_array(arr, 4) == false);
    assert(is_number_on_array(arr, 98) == true);
    assert(is_number_on_array(arr, 512) == false);

    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    tests(); // run self-test implementations
    return 0;
}
```

#### Typical structure of a program

```c
/**
 * @file
 * @brief Add one line description here. Should contain a Wikipedia
 * link or another source explaining the algorithm/implementation.
 * @details
 * This is a multi-line
 * description containing links, references,
 * math equations, etc.
 * @author [Name](https://github.com/handle)
 * @see related_file.c, another_file.c
 */

#include <assert.h>   /// for assert
#include              /// for `some function here`

/**
 * @brief Struct documentation
 */
struct struct_name {
    int variable;  ///< short info of this variable
    char message;  ///< short info
};

/**
 * @brief Function documentation
 * @param param1 one-line info about param1
 * @param param2 one-line info about param2
 * @returns `true` if ...
 * @returns `false` if ...
 */
bool func(int param1, int param2) {
    // function statements here
    if (/*something bad*/) {
        return false;
    }

    return true;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    /* desciptions of the following test */
    assert(func(...) == ...); // this ensures that the algorithm works as expected

    // can have multiple checks

    // this lets the user know that the tests passed
    printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // run self-test implementations
    // code here
    return 0;
}
```

#### File name guidelines

- Use lowercase words with ``"_"`` as a separator
- For instance

```markdown
MyNewCStruct.C       is incorrect
my_new_c_struct.c    is correct format
```

- It will be used to dynamically create a directory of files and implementation.
- File name validation will run on Docker to ensure validity.
- If an implementation of the algorithm already exists and your version is different from that implemented, please use an incremental numeric digit as a suffix. For example: if `median_search.c` already exists in the `search` folder, and you are contributing a new implementation, the filename should be `median_search2.c`. For a third implementation, `median_search3.c`, and so on.

#### Directory guidelines

- We recommend adding files to existing directories as much as possible.
- Use lowercase words with ``"_"`` as a separator ( no spaces or ```"-"``` allowed )
- For instance

```markdown
SomeNew Fancy-Category          is incorrect
some_new_fancy_category         is correct
```

- Filepaths will be used to dynamically create a directory of our algorithms.
- Filepath validation will run on GitHub Actions to ensure compliance.

##### Integrating CMake in a new directory

In case a new directory is 100% required, `CMakeLists.txt` file in the root directory needs to be updated, and a new `CMakeLists.txt` file needs to be created within the new directory.

An example of how your new `CMakeLists.txt` file should look like. Note that if there are any extra libraries/setup required, you must include that in this file as well.

```cmake
# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. The RELATIVE flag makes it easier to extract an executable's name
# automatically.

file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )
foreach( testsourcefile ${APP_SOURCES} )
    string( REPLACE ".c" "" testname ${testsourcefile} ) # File type. Example: `.c`
    add_executable( ${testname} ${testsourcefile} )

    if(OpenMP_C_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_C)
    endif()
    if(MATH_LIBRARY)
        target_link_libraries(${testname} ${MATH_LIBRARY})
    endif()
    install(TARGETS ${testname} DESTINATION "bin/<foldername>") # Folder name. Do NOT include `<>`

endforeach( testsourcefile ${APP_SOURCES} )
```

The `CMakeLists.txt` file in the root directory should be updated to include the new directory.\
Include your new directory after the last subdirectory. Example:

```cmake
...
add_subdirectory(numerical_methods)
add_subdirectory(<foldername>)
```

#### Commit Guidelines

- It is recommended to keep your changes grouped logically within individual commits. Maintainers find it easier to understand changes that are logically spilled across multiple commits. Try to modify just one or two files in the same directory. Pull requests that span multiple directories are often rejected.

```bash
git add file_xyz.c
git commit -m "your message"
```

Examples of commit messages with semantic prefixes:

```markdown
fix: xyz algorithm bug
feat: add xyx algorithm, struct xyz
test: add test for xyz algorithm
docs: add comments and explanation to xyz algorithm
chore: update Gitpod badge
```

Common prefixes:

- fix: A bug fix
- feat: A new feature
- docs: Documentation changes
- test: Correct existing tests or add new ones
- chore: Miscellaneous changes that do not match any of the above.

### Pull Requests

- Checkout our [pull request template](https://github.com/TheAlgorithms/C/blob/master/.github/pull_request_template.md)

#### Building Locally

Before submitting a pull request, build the code locally or using the convenient [![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-Ready--to--Code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/TheAlgorithms/C) service.

```bash
cmake -B build -S .
```

#### Static Code Analyzer

We use [`clang-tidy`](https://clang.llvm.org/extra/clang-tidy/) as a static code analyzer with a configuration in [`.clang-tidy`](.clang-tidy).

```bash
clang-tidy --fix --quiet -p build subfolder/file_to_check.c --
```

#### Code Formatter

[**`clang-format`**](https://clang.llvm.org/docs/ClangFormat.html) is used for code formatting.

- Installation (only needs to be installed once.)
  - Mac (using home-brew): `brew install clang-format`
  - Mac (using macports): `sudo port install clang-10 +analyzer`
  - Windows (MSYS2 64-bit): `pacman -S mingw-w64-x86_64-clang-tools-extra`
  - Linux (Debian): `sudo apt-get install clang-format-10 clang-tidy-10`
- Running (all platforms): `clang-format -i -style="file" my_file.c`

#### GitHub Actions

- Enable GitHub Actions on your fork of the repository.
After enabling, it will execute `clang-tidy` and `clang-format` after every push (not a commit).
  - Click on the tab "Actions", then click on the big green button to enable it.

![GitHub Actions](https://user-images.githubusercontent.com/51391473/94609466-6e925100-0264-11eb-9d6f-3706190eab2b.png)

- The result can create another commit if the actions made any changes on your behalf.
- Hence, it is better to wait and check the results of GitHub Actions after every push.
- Run `git pull` in your local clone if these actions made many changes to avoid merge conflicts.

Most importantly,

- Happy coding!
