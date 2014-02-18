module StringInput (String, Init, clk, Shift, rst, Regin);
  input [76:0] String;
  input Init;
  input clk;
  input Shift;
  input rst;
  output reg [76:0] Regin;

initial begin
	Regin=77'b0;
end

always @(negedge clk) begin
	if(rst)begin
		Regin=77'b0;
	end
	else begin
		if(Init)
			Regin=String;
		else begin
			if(Shift)
				Regin={Regin[75:0],1'b0};
			else
				Regin=Regin;
		end
	end
end
endmodule

		
