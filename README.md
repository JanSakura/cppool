# cppool
C++简单的工具集合, 标准尽量追新, 现在为C++14;

追求单h+cpp文件组合解决指定方面问题, 尽量不引用多个非标准库头文件

cpp simple tools collection



## 流程控制

### finally

通过C++的析构特性, 设计的最终执行模板方法, 在离开作用域时执行, 某种意义上的真finally.

对比: Java的finally是作用在异常处理的try-catch-finally作用域的.



## 密码学、位操作部分

### 位操作

这部分的默认Byte为8Bit, 密码学中一般使用unsigned char* 为Byte串。



#### 获取/设置byte串某一bit的数值

#### 计算byte串中bit值为1或0的数量

C++20 采用bit库的std::popcount函数; 其他采用Brian Kernighan算法

#### 是否为2的幂



#### 循环左移、循环右移

示例：a,b,c,d,e,f,g,h  循环左移后: b,c,d,e,f,g,h,a.

这里的循环位移,起始点都是从低字节的低位开始,即data\[0][0],...,data\[0]\[7],data\[1][0],...data\[len -1][0],...,data\[len -1][8]

每一位bit的下标index为 byte_index * 8 + inner_bit_index

而C++默认的位运算符, 如左移<<, 则是将最高位移除出去, 与这里的操作是相反的.



### 填充（主要是为了密码学）

原理:The Public-Key Cryptography Standards (PKCS)

#### PKCS7 Padding

示例: 对于byte串最后, 如果分组块block size为8, 填充前最后多出来0xA1, 则填充后为 0xA1 0x07 0x07 0x07 0x07 0x07 0x07 0x07.

算法: 将byte串填充到分组块大小的整数倍, 最后填充的相同的字节,该相同字节的值即为填充的数目(ASCII码形式); 当已经恰好为整数倍,则再填充一个分组块,每个值为block size对应的ASCII码.

PKCS7相比于PKCS5的区别: 

* PKCS5默认填充到8 byte,而PKCS7则可以修改这个填充的块大小, 一般是在1~255.

因此PKCS5属于PKCS7的一种特殊情况, 一种子集算法.





## 扩展

针对std内一些东西的修改,扩展

std::endl改为stdex::linefeed, 即用常量字符"\n"代替.