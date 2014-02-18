module CharComparator(
input [3:0] char_count, 
output CharReady
);
   assign CharReady = (~| char_count);
endmodule
