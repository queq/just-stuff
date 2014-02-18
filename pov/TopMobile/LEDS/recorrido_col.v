
`timescale 1ns / 1ps
module recorrido_col(clk_out,load_crt,done_crt,dir, new_col,reset_new);
	input 		clk_out;			//REcorido de direcciones de ram con clk_out para impresion
	input		load_crt;
	input		reset_new;
	output	reg done_crt;
	output wire [7:0] dir;
	output	reg	new_col;
 
	reg [7:0]	col;
	parameter 	maxCol=79 ;//=255;   

always @(posedge clk_out or posedge load_crt)begin
	
if (load_crt == 1)begin col<=8'b0;
				done_crt<=1'b0;
		end 
		else if (col<maxCol)col<=col+1;
		else begin 
		col<=col;
		done_crt<=1'b1;
		end

end

		assign dir =col;
always @(posedge clk_out or posedge reset_new) begin
		if(reset_new==1)new_col<=1'b0;
			else begin
			new_col<=1'b1;
			end 
		
	end
endmodule

