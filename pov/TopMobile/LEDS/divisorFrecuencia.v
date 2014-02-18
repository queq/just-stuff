module divisor_de_frecuecia(rst,clk,clk_out); ////0.000189933 s/0.000001 s fpga
    input clk;
    output reg clk_out;
    input rst;
    reg [16:0] counter;
 always @(posedge clk)
    begin
      if(rst)
       begin
    counter<=17'b0;
       clk_out <= 1'b1;
       end
     else if(counter==17'b11111111111000100)//va convertir un clk de 50Mh a un 10kh
         begin
         counter<=17'd0;
         clk_out <= ~clk_out;
         end
			else  begin
       counter<=counter+1;
       end
   end
endmodule
