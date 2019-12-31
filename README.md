# CountryServer

This server is a open source part of all system . It is use to build in several city. When a phone installed our app , it will connect to nearest server and start detecting any shake . If the phone detect a shake which like earthquake , it will alert people with ring and send a message to server . When server receives messages , it will computes the credibility from each message to determine whether the earthquake occur , if yes , it will send alert to every device connecting with it .

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

Warning : This project is developing in centos 7, so this install part is for centos 7.

### Prerequisites

1.Update yum :
```
yum install -y epel-release
yum update –y
```
2.install package :
```
yum install -y make libev libev-devel wget gcc gcc-c++ hiredis-devel redis
```
3.install proto :
```
mkdir proto //create a folder
cd proto
wget https://github.com/google/protobuf/releases/download/v2.6.1/protobuf-2.6.1.tar.gz 
tar xvf protobuf-2.6.1.tar.gz 
cd protobuf-2.6.1 
./configure 
make 
make install 
```
4.install proto_c :
```
mkdir proto_c //create a folder
cd proto_c 
wget https://github.com/protobuf-c/protobuf-c/releases/download/v1.3.1/protobuf-c-1.3.1.tar.gz 
tar xvf protobuf-c-1.3.1.tar.gz 
cd protobuf-c-1.3.1
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig 
export LD_LIBRARY_PATH=/usr/local/lib 
./configure 
make 
make install 
```
If you encounter error such like
“protoc: error while loading shared libraries: libprotoc.so.9: cannot open shared object file”Use this command to solved
```
export LD_LIBRARY_PATH=/usr/local/lib
```
4.Run redis server :
```
sudo systemctl start redis
```

### Installing

Download This project :
```
git clone “ url “
```
Run server :
```
make
./server –p [port you want open]
```
Example : 
```
./server –p8008
```

## Warning
This country server need connect to our bootstrap server to work :
1. This server need to registered in our data base first, or our bootstrap server will not allocate user connect to your server. 
2. If you want to register, please send your IP and Mac address to  our E-mail : "ncumwnl337@gmail.com" , we will check and add you into data base as soon as possible.

This server is in developing stage, so it have bugs we know but still not  solved :
1. Segmentation fault when receive udp packet not use our proto file to format.



## Built With

* [Libev](https://github.com/enki/libev) - For nonblocking UDP server
* [protobuf](https://github.com/protocolbuffers/protobuf) - Used to generate and manager our packet format
* [redis](https://redis.io/) - Data base

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning.


## Authors
* [ncu106503522](https://github.com/ncu106503522)
* mwnl lab


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details




