// SPDX-License-Identifier: MIT
 pragma solidity ^0.8.0;

 contract Bank {

     address private accOwner;
     uint256 private balance = 0;

     constructor() {
         accOwner = msg.sender;
     }

     // Deposit money
     function Deposit() public payable {
         require(msg.sender == accOwner,
             "You are not the account owner!");

         require(msg.value > 0,
             "Amount should be greater than 0.");

         balance += msg.value;
     }

     // Withdraw money
     function Withdraw(uint256 amount) public {
         require(msg.sender == accOwner,
             "You are not the account owner!");

         require(amount > 0,
             "Withdrawal amount must be greater than 0.");

         require(amount <= balance,
             "Insufficient balance!");

         balance -= amount;

         (bool success, ) =
             payable(accOwner).call{value: amount}("");

         require(success, "Transfer failed!");
     }

     // Show balance
     function showBalance() public view returns (uint256) {
         require(msg.sender == accOwner,
             "You are not the account owner!");

         return balance;
     }
 }