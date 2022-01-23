## Hashtable functions  

### How to:  
1. Store information into a hashtable:  
	- Declare a "hashtable" variable. (See the hashtable.h file for the struct: t_hashtable.)  
	- Determin an "array_len":  
		Decide a number as a starting point.(Here I take the data amount * 2)  
		Using the "ft_next_prime()" function to get the nex prime number.  
	- Create/initiate the hashtable using "ft_create_hashtable();  
	- Take the data, hashtable and array_len and write a function to populate the hashtable.  
		- Using the "ft_monkey_hash()" to find the "hash index".  
		- Using the "ft_create_element()" to create the "key/value" element and store it inside the array.  

2. Add or delete key/value pair.
	- Use "ft_add_element()" function to store new key/value pair into the hashtable. 
	- Use "ft_delete_element()"  function to delete key/value pair.  
	- These functions will return the pointer to the hashtable.  

3. Retrive the value from a key:  
	- Using the "ft_get_value()".  

4. "ft_free_hashtable()" to totaly free the hashtable given.  
