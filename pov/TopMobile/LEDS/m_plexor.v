`timescale 1ns / 1ps
module m_plexor(
    input [76:0]string,
	 input [3:0] n_ascci,
    output reg [6:0]ascci,
	 output reg [6:0] efect   
    );
	 
always @(n_ascci) begin
case(n_ascci)
     		4'd0: 	begin			
							ascci=string[6:0];
							end
					
     		4'd1: 	begin			
							ascci=string[13:7];
							end
			4'd2: 	begin			
							ascci=string[20:14];
							end	
			4'd3: 	begin			
							ascci=string[27:21];
							end
			4'd4: 	begin			
							ascci=string[34:28];
							end
			4'd5: 	begin			
							ascci=string[41:35];
							end
			4'd6: 	begin			
							ascci=string[48:42];
							end
			4'd7: 	begin			
							ascci=string[55:49];
							end
			4'd8: 	begin			
							ascci=string[62:56];
							end
			4'd9: 	begin			
							ascci=string[69:63];
							end
						
			default:
					begin
					ascci=7'd0;
					end
		endcase
		efect=string[76:70];
		end
endmodule

