<project xmlns="com.autoesl.autopilot.project" name="FFT" top="fft">
    <files>
        <file name="fft.cpp" sc="0" tb="false" cflags="" csimflags=""/>
        <file name="../../fft_test.cpp" sc="0" tb="1" cflags="-DHW_COSIM" csimflags=""/>
    </files>
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow askAgain="false" name="csim" setup="true" clean="true" csimMode="2" lastCsimMode="2"/>
    </Simulation>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

