# Prove-CLT-in-CPP
This project inspired by 3Blue1Brown. When I watch the [But what is the Central Limit Theorem?](https://www.youtube.com/watch?v=zeJD6dqJ5lo), I notice the dice example is a good trail for  programming to "draw" a normal distribution curve. So I write C++ codes and use PPM format image to prove it and try more probability to draw diffderent images. The results of different conditions like magic of nature and math. I want to more people can use computer to see the "magic" by themselves.

If you can read Chinese, there is a blog to describe the details and some trials (two URL are same, choose which you can fast access):

 - My Blog Site URL: [《使用 C 语言验证非均匀概率的离散事件在样本数量足够大时，符合正态分布曲线（通过生成一个PPM格式的图像）》](https://zhonguncle.github.io/blogs/e78f83ae476fb30a2b0f619e9338dcae.html)
 - CSDN URL: [《使用 C 语言验证非均匀概率的离散事件在样本数量足够大时，符合正态分布曲线（通过生成一个PPM格式的图像）》](https://blog.csdn.net/qq_33919450/article/details/130706860)

If you are good at Chinese, you maybe can help me translate it to your language.

If you are curious about the meaning of some codes, you can read the blog, the comments of code will answer your question. If you can't read Chinese and you don't trust the auto-tranlate, please ask me.

## Usage
### size of image
The size of PPM image control by `width` and `height` in line 28-19. If you change how many times added, the number of trail samples or probability, you should change the size to display entire chart.

### how many times added
In line 51 you can change the number of times added.

### number of trail samples
In line 48 you can change the number of trail samples.


### probability of elements
In source code, there is an array `a[]` control probability of different elements. By default, the `a[]` is `{1, 2, 3, 4, 5, 6}`, it means each element have same probability, 1/6.
 
If you change the array, the probability of elements will change. For example, if the array is `{1, 2, 3, 4, 5, 6, 6, 6, 6, 6}`, the probability of `6` is 1/2 (5/10), probability of other elements is 1/10. I leave a extreme situation in comment, the probability of `1` is 0.95 and others are 0.01, you can try it. The image will be like:

![](https://zhonguncle.github.io/assets/images/7f03e7b0b2764a908d29aab45a2c8d0b.jpeg)

### Build and run
After setting, you can run this command:

```
$ g++ pclt.cpp && ./a.out 
```

It will generate a PPM image called `output-image.ppm`. The directory will be like:

![](https://zhonguncle.github.io/assets/images/38978f6df405b66f615620d59a23c693.png)

You can see a nice image of normal distribution curve.

## LICENSE
If you want to use codes and contents outside of education or personal usage (including blog), please credit the original.