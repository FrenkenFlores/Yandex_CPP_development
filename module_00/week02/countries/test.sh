clang++ countries.cpp -o countries
cat input_1.txt | ./countries > my_output_1.txt
cat input_2.txt | ./countries > my_output_2.txt
cat input_3.txt | ./countries > my_output_3.txt
diff my_output_1.txt output_1.txt
diff my_output_2.txt output_2.txt
diff my_output_3.txt output_3.txt
#rm countries my_output_1.txt my_output_2.txt my_output_3.txt