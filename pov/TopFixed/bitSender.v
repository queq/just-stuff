module bitSender(Char, ParityBit, GenerateData, SendData, Reset, clk, SendBit, DataChar,clkSend, Generated);

	input [0:6] Char;
	input ParityBit;
	input GenerateData;
	input SendData;
	input Reset;
	input clk;
	input clkSend;

	output reg SendBit;
	output reg [0:9] DataChar;
	output reg Generated;
	reg [0:9]DataCharTemp;
	
	
	
	always@(posedge clk) begin

		if (Reset)begin
			DataCharTemp <= 0;
		end
		else begin
			if(GenerateData) begin
				DataCharTemp <= {1'b1,ParityBit,Char,1'b0 };
			end
		end	
	end
	
always@(posedge clkSend )begin

	if (Reset)begin
			DataChar <= 0;
			SendBit <= 1;
			Generated <= 0;
	end
	else begin

		if (GenerateData)begin
			DataChar <= DataCharTemp;
			SendBit <= 1;
			Generated <= 1;
		end
		else begin
			if(SendData)begin
				SendBit <= DataChar[9];
				DataChar <= {1'b0,DataChar[0:8]};
				Generated <= 0;
			end
			else begin
				SendBit <= 1;
				Generated <= 0;
			end
		end
	end
end

endmodule
