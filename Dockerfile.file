FROM ubuntu
RUN apt-get update \
	&& apt-get install -y g++ \
	make \
	git
	
RUN cd /home \
&& git clone https://github.com/tarakan012/TestDocker.git \
&& cd /home/TestDocker && g++ -lm -o output main.cpp \
&& ./output

CMD ["bash"]