# tiny_mprpc
一个简易的rpc框架。在Linux环境下用C++语言开发。用于学习C++编程和分布式知识。

采用protobuf进行序列化和反序列化。采用muduo库进行网络传输。

运行方法:
进入bin目录
服务端运行 ./provider -i test.conf
客户端运行 ./consumer -i test.conf

框架使用方法：
在服务端使用NotifyService()发布rpc服务，服务类中定义相应的方法。在proto文件中添加服务
在客户端通过stub类进行rpc调用。

