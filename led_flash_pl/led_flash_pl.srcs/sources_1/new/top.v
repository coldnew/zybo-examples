`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 06/29/2016 05:19:51 PM
// Design Name:
// Module Name: top
// Project Name:
// Target Devices:
// Tool Versions:
// Description: Ligh up on-board LEDs every second
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////

module top(output [3:0] led,
           input clk);

   reg [3:0]     led;
   reg [26:0]    counter;

   always @(posedge clk) begin
      if (counter == 27'd1250000000) begin
         led <= led + 1;
         counter <= 0;
      end else begin
         counter <= counter +1;
      end
   end

endmodule
