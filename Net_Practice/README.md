# Net Practice
Configure small-scale networks. <br>
- Click [here](https://ricardoreves.github.io/42-net-practice/) to start training.
## Resources
[`Simple Guide`](https://github.com/ricardoreves/42-net-practice) <br>
[`Tutorial`](https://github.com/tblaase/Net_Practice) <br>
[`Detailed Tutorial:`](https://github.com/lpaube/NetPractice) <br>

## Levels
(modified with ChatGPT based on Detailed Tutorial above)<br>
<details>
  <summary>Level 1</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level1_paint.png?raw=true" alt="level1">  
  <br>
  <br>

**1.** Subnet mask shows the format of how an IP address is divided into its network and host components.<br>
<br>
Since Client A and Client B are on the same network, their IP addresses must share the same network portion (**104.96.23**). The host portion can differ between devices on the same network.<br>
<br>
`How to determine the range of usable IPs (Internet Protocal address)?`<br>
The subnet mask determines the format:
```
MASK can have 2 representations:
A: 255.255.255.0
B: /24
(both have the same value in BIN)
BIN: 11111111.11111111.11111111.00000000
```
`Translation A`<br>
0 out of 256 ports are used for the network. Hence, we have 256 possible ports for the host.<br>
`Translation B`<br>
The first 24 bits are network portion, and the last 32-24=**8** bits are host portion, which can be assigned to hosts-- 2^**8** = 256 possible ports.
<br>
***

In this exercise, assuming there's no subnets, the available IP range for host addresses is **104.96.23.0~255**.<br>
The range excludes:<br>
- **104.96.23.0** (the network address): The first address always represents the network itself and can't be assigned to any host.
- **104.96.23.255** (the broadcast address): The last address is always used to communicate with all devices on the network simultaneously.
- **104.96.23.12**: This IP is already taken by Client B.<br>
(Don't be afraid, the answer can be simply the first address **1**)<br>

**2.** Same as **1.**, but the subnet mask is **255.255.0.0**. The first 2 bytes of the IP address will represent the network; and the last 2 bytes, the host address.
<br>
The solution will be anything in the range of **211.191.0.0 - 211.191.255.255**, excluding:

- **211.191.0.0:** Represents the network address.
- **211.191.255.255:** Represents the broadcast address.
- **211.191.89.75:** Already taken by host _Client C_.
</br>

</details>

---

<details>
  <summary>Level 2</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level2_paint.png?raw=true" alt="level2">
  <br>
  <br>
First of all, we need to know that:<br>
The subnet mask determines the size of the subnet.<br><br>

Yes, submasks are used to divide the main network (255.255.255.0) into smaller subnets.<br>
<br>
For example, a /24 (255.255.255.0) network can be divided into multiple /29 (255.255.255.248) subnets:
<br>
_Each subnet has 256-248 = 2^3 = 8 possible ports._
<br>
`For a main network 192.168.1.0/24, you could have:`<br>
```
Subnet A: 192.168.1.0/29
Network Address: 192.168.1.0
Usable: 192.168.1.1~6
Broadcast: 192.168.1.7
```
```
Subnet B: 192.168.1.8/29
Network Address: 192.168.1.8
Usable: 192.168.1.9~14
Broadcast: 192.168.1.15
```
...<br>
and so on.<br><br>
**1.** Since _Client B_ is on the same private network as _Client A_, they should have the exact same subnet mask.
<br>
The solution can only be **255.255.255.224**.

***

**2.** To calculate the IP range of the subnet mask of _255.255.255.224_, you can <br>
##### a. perform a `Bitwise AND` operation with the IP _192.168.20.222_ of _Client B_:

<center>
  
```
IP Address:     11000000.10101000.00010100.11011101 (192.168.20.222)
Subnet Mask:    11111111.11111111.11111111.11100000 (255.255.255.224)
Network Address:11000000.10101000.00010100.11000000 (192.168.20.192)
```

</center>

As we can see, this subnet block has the size of **32** and starts at **192.168.20.192**, falling in the range of 192.168.20.**192~223**.<br>
<br><br>
##### Or b. calculate the size of each subnet block and determine in which block it is:
_255.255.255.224_ says the size of the subnet is **256-224 = 32**,<br>
and by **222÷32 ≒ 6.94** with the IP _192.168.20.**222**_ of _Client B_,<br>
we know that this IP falls in the later part of the block **6**. That means the address of the subnet is 32x6 = **192**.


The range is 192.168.20.**192~223**:
<br>

- **192.168.20.192:** Represents the network address.
- **192.168.20.223:** Represents the broadcast address.
- **192.168.20.222:** _Client B_ already has that address.

***

**3.** Here we are introduced the slash "/" notation for the subnet mask on _Interface D1_. A subnet mask of _/30_ means that the first 30 bits of the IP address represent the network address, and the remaining 2 bits represent the host address:

<center>

```
Mask /30: 11111111.11111111.11111111.11111100
```

</center>

We can see that this binary number corresponds to the decimal _255.255.255.252_, therefore it is identical to the mask found on _Interface C1_.
<br>
<br>
The answers can then be any address, as long as they meet the following conditions:

- If you're assigning IP addresses for devices within a private network (such as a home, office, or internal network that isn't directly connected to the public internet), the IP addresses should be chosen from one of the private IP address spaces (**192.168.0.0**/16 address block)
- The network address (first 30 bits) must be identical for _Client D_ and _Client C_.
- The host bits (last 2 bits) cannot be all 1, nor all 0.
- _Client D_ and _Client C_ do not have identical IP addresses.
</br>
ex. 192.168.0.1~2

</br>

</details>

---

<details>
  <summary>Level 3</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level3_paint.png?raw=true" alt="level3">
  <br>
  <br>

This exercise introduces the use of the **switch** (_Switch S_ in this example). The switch links multiple hosts of the same network together.
<br>
<br>

**1.** _Client A_, _Client B_, and _Client C_ are all on the same network. Therefore, they must all have the same subnet mask. Since _Client C_ already has the mask _255.255.255.128_, the mask for _Interface B1_ and for _Interface A1_ will also be _255.255.255.128_ (or in slash notation: _/25_).
<br>
<br>
The IP address of _Interface B1_ and _Interface C1_ must be on the same network range as the IP of _Client A_. This range is:

  <center>

```
104.198.241.0 - 104.198.241.128
```

  </center>
  Excluding of course the network address and the broadcast address.

</br>

</details>

---

<details>
  <summary>Level 4</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level4_paint.png?raw=true" alt="level4">
  <br>
  <br>

This exercise introduces the **router**. The router is used to link multiple networks together. It does so with the use of multiple interfaces (_Interface R1_, _Interface R2_, and _Interface R3_ in this example).
<br>
<br>

**1.** Since none of the masks on _Interface B1_, _Interface A1_, and _Interface R1_ are entered, we are free to choose our own subnet mask. A mask of **/24** is ideal as it leaves us with the entire 4th byte for the host address, and does not require binary calculations to find the range of possible host addresses.
<br>
<br>
The IP address of _Interface B1_ and _Interface R1_ must have the same network address as the IP address of _Interface A1_. With a subnet of _/24_, the possible range is:

  <center>

```
85.17.5.0 - 85.17.5.255
```

  </center>
  Excluding the network address and the broadcast address.
  <br>
  <br>

Note that we did not interact with the router _Interface R2_ and _Interface R3_, since none of our communications had to reach these sides of the router.

</br>

</details>

---

<details>
  <summary>Level 5</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level5_paint.png?raw=true" alt="level5">
  <br>
  <br>

This level introduces **routes**. A route contains 2 fields, the first one is the **destination** of outbound packets, the second one is the **next hop** of the packets.
<br><br>
In order to make routers work, each machine must define a route to the router, with which it also needs to define the interface IP and mask.
<br><br>
The **destination** is where the packet is supposed to end up. If there isn’t one, the default route (0.0.0.0/0) is used, which says, "Send all unknown traffic to the next hop."
<br><br>
The **next hop** is the IP address of the next device in the path toward the destination. For Client A, this would be Router R1 (because R1 is the first router along the way to Client B). 
  <br>
  <br>

**1.** _Client A_ only has 1 route through which it can send its packets. By simply setting the  destination to _default_ will send the packets to the only path available.
<br>
<br>
The **next hop** address must be the IP address of the next router's interface on the packets' way. The next interface is _Interface R1_, with the IP address of _54.117.30.126_. Note that the next interface is not _Interface A1_, since this is the sender's own interface.

</br>

</details>

---

<details>
  <summary>Level 6</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level6_paint.png?raw=true" alt="level6">
  <br>
  <br>

This level introduces the **internet**. The internet behaves like a router. However, if an interface is connected directly or indirectly to the internet, it **cannot** have an IP address in the following reserved private IP ranges:

```
192.168.0.0 - 192.168.255.255 (65,536 IP addresses)
172.16.0.0 - 172.31.255.255   (1,048,576 IP addresses)
10.0.0.0 - 10.255.255.255     (16,777,216 IP addresses)
```

**1.** The **next hop** of the internet is already entered, and matches the IP address of the _Interface R2_. Therefore we only need to fix with the destination of the internet.
<br>
<br>
The internet must send its packets to _Client A_. To do so, the internet's **destination must match the network address** of _Client A_. Let's find the network address of _Client A_:
<br>
_Client A_'s mask is _255.255.255.128_, meaning the size of the subnet block is 256-128 = **128**. For 256÷128 = **2**, we know there can be only 2 blocks (0\~127, 128\~255) and this IP falls in the second block, meaning _40.178.145.**129~254**_ are available.
<br>
<br>
We can now put this address of **40.178.145.227** in the Internet destination. The **/25** following the destination address represents the mask applied to its address.<br>
128 = `1000 0000` in binary, showing that 24+1= **25** bits are used for network.
<br>
<br>
A destination of _40.178.145.227/25_ is equivalent to the destination address _40.178.145.128/25_, since the mask of _/25_ will turn all the bits after the 25th to 0 to get the destination's network address.

</br>

</details>

---

<details>
  <summary>Level 7</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level7_paint.png?raw=true" alt="level7">
  <br>
  <br>

This level introduces the concept of **overlaps**. The range of IP addresses of a network must not overlap the range of IP addresses of a separate network. Networks are separated by routers
<br>
<br>

**1.** We have 3 separate networks:
<br>

1. Between _Client A_ and _Router R1_.
2. Between _Router R1_ and _Router R2_.
3. Between _Router R2_ and _Client C_.

For _Interface A1_, we cannot choose our IP address freely since the IP of _Interface R11_ is already entered. Also, if we give it a mask of _/24_, the IP address range will overlap with the range of _Interface R12_, which is already entered. They would both be in the range of _93.198.14.0 - 93.198.14.255_.
<br>
<br>

Since we need addresses for 3 separate networks, we have to split the last bytes of the address into at least 4 address ranges. Here I divide it into 4 blocks for example: the size of each subnet should be 256÷4= **64**.
<br>
```
Therefore possible range is as follows:
93.198.14.0 ~ 93.198.14.63
93.198.14.64 ~ 93.198.14.127
93.198.14.128 ~ 93.198.14.191
93.198.14.192 ~ 93.198.14.255
```

Assign the IPs separately by your choice.<br>
<br>
**2.** The destination of each route can be set to default, and the next hop should be the **next router**. Both routers should put each other as the next hop.
</br>

</details>

---

<details>
  <summary>Level 8</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level8_paint.png?raw=true" alt="level8">
  <br>
  <br>

**0.** Before we start, do you notice that the Internet has different IP than the local network? That's because the 163.136.250.x is a **public IP address** and the 49.175.13.x is a **private IP address**.<br>
In this exercise we focus rather on the private IP address.<br><br>
**1.**  In the scenario where there are **multiple** machines behind a router on a local network (like in the image you linked), the **destination** for the incoming packets from the Internet would typically be the public IP of the **router** or gateway. The internet sends packets to the destination _49.175.13.0/26_, aka the network address of our main network. Since it's /26, only 6 out of 32 bits are reserved for hosts, meaning this _**main network**_ has the size of 2^**6** = **64**, ranging `49.175.13.0~63`.
<br>
<br>
In order to create at least 3 non-overlapping subnets under a network of the size of 64, I choose to divide it up into 4 subnets of the size of 16: (255.255.255.240 or /28)<br>
`PS. Only 16 out of 256 are for hosts, therefore 256-16 = 240.`<br>
`PPS. For 16 = 2^4, 4 out of 32 bits are for hosts, therefore 32-4 = 28.`
```
49.175.13.0 - 49.175.13.15
49.175.13.16 - 49.175.13.31
49.175.13.32 - 49.175.13.47
49.175.13.48 - 49.175.13.63
```

<br>
<br>

**3.** The destination and next hop for the internet are already entered. We only need to enter the next hop for the _Router R2_, which is the IP on the _Interface R21_.
</br>

</details>

---

<details>
  <summary>Level 9</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level9_paint.png?raw=true" alt="level9">
  <br>
  <br>

This level is a small exercise of what we've learned so far. Since the internet does not initially send packets to a _specific network_. We don't have to divide the main network and have the liberty to **create up to 3 networks**. (because there are only 3 destinations on the `Internet Routes`.
<br>
<br>
Remember, if an interface is connected directly or indirectly to the internet, it **cannot** have an IP address in the following reserved private IP ranges:

```
192.168.0.0 - 192.168.255.255 (65,536 IP addresses)
172.16.0.0 - 172.31.255.255   (1,048,576 IP addresses)
10.0.0.0 - 10.255.255.255     (16,777,216 IP addresses)
```
Therefore, I have created the following destinations for the Internet:
`1.0.0.0/24` for the network on the left (A1-B1-R11);<br>
`2.0.0.0/24` for the network on the right (C1-R22).<br>
(The IP of the network at the bottom (D1-R23) is pre-determined and it doesn't have to connect to the Internet, so we don't have to put a thrid destination. However, as a challenge, can you find the network address of this network?)

<br>
<br>

**1.** `Network on the left (A1-B1-R11)`<br>
Put the same mask and assign IP **1.0.0.1~254** of your choice.<br>
Put the IP of R11 to the **next hops** of both clients.
<br>
<br>
**2.** `Network on the right (C1-R22)`<br>
Simply put the basic mask **255.255.255.0 (/24)** and assign IP **2.0.0.1~254** of your choice.<br>
Put the IP of R21 to the **next hops** of both clients.
<br>
<br>
**3.** `Network at the bottom (D1-R23)`<br>
Put the same mask and assign IP as you please<br>
(/18 is quite big, so a simple 73.110.148.12 would do the trick)
<br>
<br>
**4.** Assign a simple IP **3.0.0.1~254** to the routers and put the IP of one router to the other one's **net hop**.
<br>
<br>
It is normal to have an empty field for the 3rd destination of the _internet_, and in _Router R1's_ destination. Not all fields of the routing tables need to be filled.
<br>
<br>
**[Bonus]** The network address of the network at the bottom is `73.110.128.0/18`.<br>
/18=8+8+2 shows that there are **6 bits** can be used for hosts in the third octet.<br>
So the block size would be 2^6 = **64**, and 148÷64=2.x, meaning it's the second block.<br>
So we have 64×2 = **128** in `73.110.128.0/18` as the address of the network, and if we assign this address as the third destination route of the Internet, D1 would be able to connect to the Internet as well.
<br>
<br>
</details>

---

<details>
  <summary>Level 10</summary>
  <br>
  <img src="https://github.com/LPaube/42_NetPractice/blob/main/img/level10_paint.png?raw=true" alt="level10">
  <br>
  <br>

At this level, there are 4 different networks:
<br>

1. _Router R1_ to _Switch S1_
2. _Router R1_ to _Router R2_
3. _Router R2_ to _Client H4_
4. _Router R2_ to _Client H3_
   <br>

**1.** The internet must be able to send its packets to all the hosts, so its destination must cover the range of networks of all the hosts.
<br>
<br>

_Interface R11_ and _Interface R13_ already have an IP address entered. This IP address only differs in its last byte. _Interface R11_ has for last byte **1**, and _Interface R13_ has for last byte **254**. To cover this wide range to IP addresses, we take a mask of **/24** for the _internet's_ destination. This destination will cover a range of `70.101.30.0 - 70.101.30.255`.

  <br>
  <br>

**2.** When choosing the IP addresses, we must make sure of 2 things:
<br>

1. The IP address is covered by the _internet_ destination.
2. The IP address range of the various networks does not overlap.
   <br>

With the IP addresses already entered (greyed out), let's examine the ranges covered by the various networks:
<br>

1. _Router R1_ to _Switch S1_ - Covers the range **70.101.30.0 - 70.101.30.127** (mask /25).
2. _Router R2_ to _Client H4_ - Covers the range **70.101.30.128 - 70.101.30.191** (mask /26).
3. _Router R1_ to _Router R2_ - Covers the range **70.101.30.252 - 70.101.30.255** (mask /30).
4. _Router R2_ to _Client H3_ - ??? (mask ???).

The only IP addresses left for the network "Router R2 to Client H3" are **70.101.30.192 - 70.101.30.251**. We can pick any mask that will let us take 2 IP addresses from that range to put in _Interface R22_ and _Interface R31_.

</br>

</details>
