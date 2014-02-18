module Parity(
input [6:0] char, 
input rxd, 
output parity
);
   assign parity = (^char) ^ rxd;
endmodule
