#!/bin/bash
protoc -I=. --cpp_out=. ./nqueens.proto
