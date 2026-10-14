#!/bin/bash

gnome-terminal -- bash -c 'echo RPC CLIENT; echo; ./rpc_client localhost; exec bash'

gnome-terminal -- bash -c 'echo RPC SERVER; echo; ./rpc_server; exec bash'

gnome-terminal -- bash -c 'echo SOCKET CLIENT; echo; ./socket_client; exec bash'


