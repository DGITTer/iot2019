pragma solidity ^0.5;

contract Lampe21Contract {
  address payable owner;
  constructor() public {
    owner = address(0x9EC058EdEeE33070dF409F2Bc11F5C52E1Ac5Bb2);
  }
  function buyLight() public payable {
    msg.sender.transfer(1000000000000000000);
  }
}