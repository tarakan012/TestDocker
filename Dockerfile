FROM ubuntu
RUN apt-get update \
	&& apt-get install -y g++ \
	make \
	git \
	wget
	
RUN cd /home && wget https://sourceforge.net/projects/boost/files/boost/1.64.0/boost_1_64_0.tar.gz \
&& tar xfz boost_1_64_0.tar.gz \
&& cd boost_1_64_0 \
&& ./bootstrap.sh --prefix=/usr/local --with-libraries=system, asio \
&& ./b2 install \
&& rm -rf boost_1_64_0

CMD ["bash"]