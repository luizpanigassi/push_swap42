# push_swap42
A sorting algorithm following some rules!

I suffered. OMFG I suffered. This was a tough one.

We are supposed to create a simple sorting algorithm to (duh) sort
numbers given as arguments when you run ./push swap 9 8 1 2 3, for instance.
As any of those who know me knows, I am TERRIBLE with numbers. So all of this was
a big challenge.

First, let's take a look at what we CAN do, cause we have some rules as for the operations
we can perform:

We have two stacks, A and B. B is empty, and A is populated by the numbers to be sorted. To
perform the sorting, we can use:

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.

(extracted verbatum from the subject)

Of course there's more. We need to use the lowest number of movements possible. So
first, choosing the algorithm. Next, preparing the movements. Then, the sorting
algorithm. Last, bundle it all up to make it work.

I've checked plenty of algorithms. Turkish sorting, quick sorting, insertion, etc.
They're all crazy. But Radix was the one I picked. It seemed simple, some people
told me it was simple enough to get my project approved, so I went for it. Videos,
texts, AI, everything helped me. Took me a while. But FINALLY I think I've got it right.

I'm using linked lists to manage the numbers, not arrays. That wasn't my first option,
but I looked at other people's codes, got some ideas, and went for it. So, using my
functions from libft (you can find my repository here), I went for it. Linked lists are
great for memory management, and they are super easy to manipulate and free.

So first, we need to validate the input. We can't have two of the same number, we need
at least one number, we can only get numbers in the arguments. Validations in place,
we need to initialize the list using the arguments. Memory allocated, list created, now we
check if we have 3, 4, 5 or more than 5 numbers. For 3, 4 and 5 numbers, Radix is too complex,
we just use simple sort.

In comes Radix. Now this is tricky. Radix sort is a non-comparative integer sorting algorithm
that leverages the concept of place value to efficiently sort data. Fancy, right? Not my words,
Gemini told me that, I couldn't explain it like that.

The idea is to order numbers by bit size. It works like this: you "create" 10 buckets, from 0 to 9.
Then, you push to stack B everything that ends in 0. Then, everything that ends in 1, in 2, and so
on. Then, it checks the second digit, and does the same. Then, the same for the third digit. So, if
stack A is 170, 45, 75, 90, 802, 24, 2, 66, things will go like this:

First, we sort by units digit:

Create 10 buckets (0-9).
Distribute numbers based on their units digit:
Bucket 0: 90, 802
Bucket 2: 2
Bucket 4: 24
Bucket 5: 45, 75
Bucket 6: 66
Bucket 7: 170
Collect numbers from buckets in order: 90, 802, 2, 24, 45, 75, 66, 170

Then, sort by tens digit:

Distribute numbers based on their tens digit:
Bucket 0: 90, 2, 802
Bucket 2: 24
Bucket 4: 45
Bucket 5: 75
Bucket 6: 66
Bucket 7: 170
Collect numbers from buckets in order: 2, 90, 802, 24, 45, 75, 66, 170

Lastly (since we only have up to hundereds), distribute numbers 
based on their hundreds digit:

Bucket 0: 2, 24, 45, 75, 66, 90
Bucket 1: 170
Bucket 8: 802
Collect numbers from buckets in order: 2, 24, 45, 66, 75, 90, 170, 802

The final result is the sorted list: 2, 24, 45, 66, 75, 90, 170, 802

And THAT's how Radix works!
