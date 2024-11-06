# Password-Generator
Simple password generator in cpp. 

### Build and run
The following code will clone, build and run the project. It creates a password with the format ```XXXX-XXXX-XXXXX``` where every ```X``` is replaced with a random symbol from ```pools/pool.txt```.
```bash
git clone https://github.com/JakobLiebig/password-generator.git password_generator
mkdir password_generator/build
cd password_generator/build
cmake ..
make
./apps/pw-gen -p ../pools/pool.txt -f XXXX-XXXX-XXXXX
```
