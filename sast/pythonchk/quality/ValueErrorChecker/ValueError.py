#value error
a_list = ['a', 'b', 'new']
a_list.index('new')
a_list.index('c')				  # @violation
a_list.remove('a')
a_list.remove('c')  		      # @violation

(a,b,c) = a_list
(d,e) = a_list					  # @violation
(a,b,c) = range(5)			      # @violation
(a,b,c) = range(2) 			      # @violation


