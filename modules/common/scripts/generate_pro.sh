#!/usr/bin/env bash

PROTO_DIR="../proto"
# cd $PROTO_DIR
# for file in *.proto;
# do echo $file
# done;
# echo $file

# echo $PROTO_DIR
protoc -I=$PROTO_DIR --cpp_out=$PROTO_DIR/cpp_out $PROTO_DIR/demo.proto