#!/bin/bash

gnome-terminal -- bash -c 'gcc -o socket_client socket_client.c; exec bash'

gnome-terminal -- bash -c 'gcc -o rpc_server rpc_server.c rpc_svc.c rpc_xdr.c; exec bash'

gnome-terminal -- bash -c 'gcc -o rpc_client rpc_client.c rpc_clnt.c rpc_xdr.c; exec bash'




