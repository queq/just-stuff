module StringComparator(
input [3:0] str_count, 
output StringReady
);
   assign StringReady = (~| str_count);
endmodule
