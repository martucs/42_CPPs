# A Ford-Johnson Guide
This exercise was very challenging for me, so I decided to give you a hopefully clear and simple explanation of this very complex algorithm. 

I mainly followed [this](https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91) article and spoke with some very talented 42 students who were able to explain to me what I didn't understand from the article.

To my understanding, this are the basic characteristics that the Ford-Johnson algorithm has:
- Divides and sorts recursively, sorting the bigger numbers to later insert the smaller numbers in their correct position
- Uses the Jacobsthal sequence to decide the insertioin order of the elements to insert

I also understood from this article that the binary serarch/insertion is also an important characteristic of this algorithm and that plays a part in the efficiency of the insertion, so I incorporated it, but it is still unclear to me wether it is necessary or not.

I used std::vector and std::deque, and I also print the comparisions made, which, because the code is exactly the same for deque and vector, are always the same in both cases.

> [!TIP]
> I also made a DEBUG mode, which was extremely useful to me when doing the insertions.

### How to use the debug mode:
To compile normally we would do 'make', so for the debug we do:

    make debug
And we get the executable:

    ./PmergeMe_debug <num1> <num2> <num3> ...

## Algorithm breakdown
I see this algorithm working in two very distinct parts:
1. Grouping and sorting
2. Inserting in the different group levels

