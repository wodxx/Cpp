# socket通信原理

## 什么是TCP/IP、UDP

>TCP/IP（Transmission Control Protocol/Internet Protocol）即传输控制协议/网间协议，是一个工业标准的协议集，它是为广域网（WANs）设计的。UDP（User Data Protocol，用户数据报协议）是与TCP相对应的协议。它是属于TCP/IP协议族中的一种。

  这里有一张图，表明了这些协议的关系:

![utshi](https://img-blog.csdnimg.cn/20190612195003894.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2tpa2l0eWFu,size_16,color_FFFFFF,t_70)

>TCP/IP协议族包括运输层、网络层、链路层。

socket的位置如下图：

![tushi](https://img-blog.csdnimg.cn/20190612195047831.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2tpa2l0eWFu,size_16,color_FFFFFF,t_70)

Socket是应用层与TCP/IP协议族通信的中间软件抽象层，它是一组接口。在设计模式中，Socket其实就是一个门面模式，(tcp/ip协议族的封装）它把复杂的TCP/IP协议族隐藏在Socket接口后面，对用户来说，一组简单的接口就是全部，让Socket去组织数据，以符合指定的协议。

## 1、网络中进程之间如何通信

进程通信方式。

网络中通信过程：

- 首要解决的问题是如何唯一标识一个进程。TCP/IP协议族已经帮我们解决了这个问题，网络层的“ip地址”可以唯一标识网络中的主机，而**传输层的“协议+端口”可以唯一标识主机中的应用程序（进程）**。这样利用三元组（ip地址，协议，端口）就可以标识网络的进程了，网络中的进程通信就可以利用这个标志与其它进程进行交互。

- 使用TCP/IP协议的应用程序通常采用应用编程接口：UNIX BSD的套接字（socket）

## 什么是Socket

ocket起源于Unix，而Unix/Linux基本哲学之一就是“一切皆文件”，都可以用“打开open –> 读写write/read –> 关闭close”模式来操作。我的理解就是Socket就是该模式的一个实现，**socket即是一种特殊的文件，一些socket函数就是对其进行的操作（读/写IO、打开、关闭）**

- socket()函数: 用于创建一个socket描述符（socket descriptor），它唯一标识一个socket

- bind()函数: 把一个地址族中的特定地址赋给socket

- listen()/connect()函数: 来监听这个socket,如果客户端这时调用connect()发出连接请求，服务器端就会接收到这个请求。

- accept()函数: TCP服务器端依次调用socket()、bind()、listen()之后，就会监听指定的socket地址了。

- TCP客户端依次调用socket()、connect()之后就想TCP服务器发送了一个连接请求。(三次握手)

- TCP服务器监听到这个请求之后，就会调用accept()函数取接收请求，这样连接就建立好了。之后就可以开始网络I/O操作了，即类同于普通文件的读写I/O操作。

- read()、write()等函数

- close()函数

## socket中TCP的三次握手建立连接详解

客户端向服务器发送一个SYN J

服务器向客户端响应一个SYN K，并对SYN J进行确认ACK J+1

客户端再想服务器发一个确认ACK K+1

![tu](https://img-blog.csdnimg.cn/20190612195514218.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2tpa2l0eWFu,size_16,color_FFFFFF,t_70)

从图中可以看出，(第一次握手)当客户端调用connect时，触发了连接请求，向服务器发送了SYN J包，这时connect进入阻塞状态；(第二次)服务器监听到连接请求，即收到SYN J包，调用accept函数接收请求向客户端发送SYN K ，ACK J+1，这时accept进入阻塞状态；(第三次)  客户端收到服务器的SYN K ，ACK J+1之后，这时connect返回，并对SYN K进行确认；服务器收到ACK K+1时，accept返回，至此三次握手完毕，连接建立。
