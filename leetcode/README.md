# 📚 Contributing 📚

We're glad you're interested in adding C LeetCode solutions to the repository.\
Here we'll be explaining how to contribute to LeetCode solutions properly.

## 💻 Cloning/setting up the project 💻

First off, you'll need to fork the repository [**here**](https://github.com/TheAlgorithms/C/fork).\
Then, you'll need to clone the repository to your local machine.

```bash
git clone https://github.com/your-username/C.git
```

After that, you'll need to create a new branch for your solution.

```bash
git checkout -b solution/your-solution-name
```

## 📝 Adding a new solution 📝

All LeetCode problems can be found [**here**](https://leetcode.com/problemset/all/).\
If you have a solution to any of these problems (which are not being [**repeated**](https://github.com/TheAlgorithms/C/blob/master/leetcode/DIRECTORY.md)), that's great! Here are the steps:

1. Add a new file in `leetcode/src` with the number of the problem.
    - For example: if the problem's number is 98, the filename should be `98.c`.
2. Provide a small description of the solution at the top of the file. A function should go below that. For example:

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
```

3. Do not provide a `main` function. Use the required standalone functions instead.
4. Doxygen documentation isn't used in LeetCode solutions. Simple/small documentation or comments should be fine.
5. Don't include libraries/headers such as `stdio.h`. Your file should be the solution to the problem only.

### 📜 Adding your new solution to the list 📜

Great! You've added your solution. Now, you'll have to add it to `leetcode/DIRECTORY.md`.\
Please use numerical order. For example: if the solution's number is `98`, add your solution after `97`, if available.

This is the required format for new solutinos:

```markdown
| <solution number>   | [<solution name>](<leetcode link to problem>)                                   | [C](./src/<filename>.c)   | <difficulty>     |
```

## 📦 Committing your changes 📦

Once you're done with adding a new LeetCode solution, it's time we make a pull request.

1. First, stage your changes.

```bash
git add leetcode/src/98.c # Use `git add .` to stage all changes.
```

2. Then, commit your changes.

```bash
git commit -m "feat: add LeetCode problem 98" -m "Commit description" # Optional
```

3. Finally, push your changes to your forked repository.

```bash
git push origin solution/your-solution-name:solution/your-solution-name
```

4. You're done now! You just have to make a [**pull request**](https://github.com/TheAlgorithms/C/compare). 🎉

If you need any help, don't hesitate to ask and join our [**Discord server**](https://the-algorithms.com/discord)! 🙂
