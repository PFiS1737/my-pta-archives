# my-pta-archives

我的 PTA 归档，使用 Java 语言。

查看 `main` 分支以获取 C++ 版本（对应数据结构课程）。

## Requirements

- jdk
- fish
- just
- fzf (optional)

## Usage

```sh
# 创建源文件
#   -n 仅创建文件而不询问内容
#   -y 默认确定
# 输入时直接换行即可，ctrl-c 到下一个问题
just new [-ny]

# 评判
just judge

# 归档当前工作区
# 提问 Description 为组成文件名的短描述
#      Problem 为具体题干
just archive

# 检出一个归档
# 不提供 id 则调用 fzf 进行搜索
just checkout [id]
```

# Reference

- [PTA](https://pintia.cn)
