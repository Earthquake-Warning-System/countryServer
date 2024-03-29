# CountryServer

This server is an open-source part of system. It is used to build in several cities. When a phone installed our app, it will connect to the nearest server and start detecting any shake. If the phone detects a shake which like earthquake, it will alert people with rings and send a message to server. When a server receives messages, it will compute the credibility from each message to determine whether the earthquake occurs, if yes, it will send alert to every device connecting with it. a open source part of all system . It is use to build in several city. When a phone installed our app , it will connect to nearest server and start detecting any shake . If the phone detect a shake which like earthquake , it will alert people with ring and send a message to server . When server receives messages , it will computes the credibility from each message to determine whether the earthquake occur , if yes , it will send alert to every device connecting with it .

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

Warning: This project is developing in centos 7, so this install part is for centos 7.

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
```sh
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
```sh
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
If you encounter an error such as
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
```sh
git clone https://github.com/ncu106503522/countryServer.git
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
1. This server needs to register in our database first, or our bootstrap server will not allocate users to connect to your server. 
2. If you want to register, please send your IP and Mac address to our E-mail: "ncumwnl337@gmail.com", we will check and add you to the database as soon as possible.


## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning.



## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details




