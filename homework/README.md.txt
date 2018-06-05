# Judge微系统
## 文件

- random.cpp ---->随机产生 test0.in 到 test9.in 的十个数据文件
- ac.cpp     ---->标程可根据10个数据输入文件生成十个test0.out 到 test9.out 的输出文件
- judge.cpp  ---->linux下判题系统
- judge_w.cpp---->windows下判题系统
- test.cpp   ---->待评测程序(设置可产生AC PE 和 WA 三种结果)

## 功能

- 可生成随机输入输出数据
- 可进行编译运行评测，并给出评测结果
- windwos下和linux下均有相应版本

## 评分系统

- AC 数据完全正确记10分
- PE 输出格式错误 结果正确 记5分
- WA 结果错误 记0分
- RE 数据文件出现问题 记 0 分
- 总分100分

## 使用方法

- 编译运行random.cpp 产生输入数据文件
- 编译运行ac.cpp     产生正确输出文件
- 编译相应版本的judge （windows和linux下不可使用 a.exe和a.out）
- 运行编译好的judge，并选择评测方式

## 注意事项

- 编译系统默认使用g++ 进行编译，请将g++填入环境变量
- linux下使用diff进行判题
- 判题过程中会产生dif.out a.out/a.exe 请不要删除。
- 所有文件请放置在同一目录下
- windows和linux下不可使用 judge的编译结果不要使用  a.exe和a.out