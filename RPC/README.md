* To compile add.x <br>
    ```rpcgen -a -C add.x```

* After updating the client & server program <br>
    ```sudo apt install make```
    ```make -f Makefile.add ```

* To start the server <br>
  ``` ./add_server```
  
* To start the client <br>
  ``` ./add_client localhost num1 num2```
  **Example:** ``` ./add_client localhost 1 2```